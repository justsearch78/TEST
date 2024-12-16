pipeline {
    agent any

    environment {
        DOCKER_IMAGE = 'justsearch78/nx'  // Docker image name
        GITHUB_REPO = 'https://github.com/justsearch78/TEST.git'  // GitHub repository
        KUBERNETES_NAMESPACE = 'default'  // Kubernetes namespace
        ARGOCD_APP_NAME = 'nx-app'  // ArgoCD application name
    }

    stages {
        stage('Checkout') {
            steps {
                git branch: 'main', url: "${GITHUB_REPO}"
            }
        }

        stage('Setup Build Environment') {
            steps {
                sh '''
                    # Install build dependencies
                    sudo apt-get update
                    sudo apt-get install -y cmake g++ make
                '''
            }
        }

        stage('Build') {
            steps {
                sh '''
                    mkdir -p build
                    cd build
                    cmake ..
                    make
                '''
            }
        }

        stage('Test') {
            steps {
                sh '''
                    cd build
                    ctest --output-on-failure || true
                '''
            }
        }

        stage('Docker Build and Push') {
            steps {
                script {
                    docker.withRegistry('https://docker.io', 'nxtest') {
                        def customImage = docker.build("${DOCKER_IMAGE}:${env.BUILD_NUMBER}")
                        customImage.push()
                        customImage.push('latest')  // Push the latest tag as well
                    }
                }
            }
        }

        stage('Update Kubernetes Manifests') {
            steps {
                script {
                    sh """
                        # Replace placeholder with Jenkins build number
                        sed -i 's|latest|${env.BUILD_NUMBER}|g' deploy/deployment.yaml

                        # Commit and push changes to GitHub
                        git config user.email "rakeshjustsearch78@gmail.com"
                        git config user.name "justsearch78"
                        git add deploy/deployment.yaml
                        git commit -m "Update deployment image to ${env.BUILD_NUMBER}"
                        git push origin main
                    """
                }
            }
        }

        stage('Trigger ArgoCD Sync') {
            steps {
                script {
                    withCredentials([
                        string(credentialsId: 'argocd-server', variable: 'ARGOCD_SERVER'),
                        string(credentialsId: 'argocd-token', variable: 'ARGOCD_TOKEN')
                    ]) {
                        sh """
                            # Login to ArgoCD
                            argocd login ${ARGOCD_SERVER} --token ${ARGOCD_TOKEN} --insecure
                            
                            # Sync the application with ArgoCD
                            argocd app sync ${ARGOCD_APP_NAME}
                            
                            # Wait for application to be fully synchronized
                            argocd app wait ${ARGOCD_APP_NAME} --timeout 600
                        """
                    }
                }
            }
        }
    }

    post {
        always {
            archiveArtifacts artifacts: 'build/*', fingerprint: true, onlyIfSuccessful: true
        }

        success {
            echo 'Build and deployment successful!'
        }

        failure {
            echo 'Build or deployment failed!'
        }
    }
}

